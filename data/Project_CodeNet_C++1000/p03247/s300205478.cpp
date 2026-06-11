#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
long long x[1010],y[1010],mx[4];
vector<long long> d;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int main(){
    int i,j,k,n,cnt = 0;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> x[i] >>y[i];
        if((x[i]+y[i])%2){
            cnt++;
        }
    }
    if(cnt!=0 && cnt!=n){
        cout << -1 << endl;
        return 0;
    }
    long long z = pow(2,31);
    while(z>=1){
        d.push_back(z);
        z /= 2;
    }
    if(!cnt){
        d.push_back(1);
    }
    int m = d.size();
    cout << m << endl;
    for(i=0;i<m;i++){
        cout << d[i] << " ";
    }
    cout << endl;
    for(i=0;i<n;i++){
        long long s = 0,t = 0;
        for(j=0;j<m;j++){
            long long mn = 100000000000000;
            for(k=0;k<4;k++){
                mx[k] = abs(x[i] - (s + dx[k]*d[j])) + abs(y[i] - (t + dy[k]*d[j]));
                mn = min(mn,mx[k]);
            }
            for(k=0;k<4;k++){
                if(mn==mx[k]){
                    if(k==0){
                        cout << "L";
                    }
                    if(k==1){
                        cout << "U";
                    }
                    if(k==2){
                        cout << "R";
                    }
                    if(k==3){
                        cout << "D";
                    }
                    s += dx[k]*d[j]; t += dy[k]*d[j];
                    break;
                }
            }

        }
        cout << endl;
    }
}