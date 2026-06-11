#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int n;
    cin >> n;

    vector<int> num(10);
    num[0]=1; num[1]=1; num[2]=1;
    bool c3,c5,c7;
    int x,t;
    int count=0;

    while(num[9]==0){
        x=0; t=1;
        c3=false; c5=false; c7=false;
        rep(i,9){
            if(num[i]==4){
                num[i]=1;
                num[i+1]++;
            }
            if(num[i]==1){
                c3=true;
                x+=3*t;
            }else if(num[i]==2){
                c5=true;
                x+=5*t;
            }else if(num[i]==3){
                c7=true;
                x+=7*t;
            }
            t*=10;
        }
        // cout << ' ' << x << endl;
        if(x>n) break;
        num[0]++;
        if(c3 && c5 && c7) count++;
    }
    
    cout << count << endl;

    return 0;
}