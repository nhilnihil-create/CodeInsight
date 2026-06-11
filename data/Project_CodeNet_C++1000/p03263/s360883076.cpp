#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int h,w;
    cin>>h>>w;
    int a[h][w];
    rep(i,h) rep(j,w) cin>>a[i][j];

    vector<int> x1,y1,x2,y2;
    rep(i,h){
        if(i%2==0){
            rep(j,w){
                if(a[i][j]%2==0) continue;
                if(j!=w-1){
                    a[i][j+1]++;
                    x1.push_back(i);
                    y1.push_back(j);
                    x2.push_back(i);
                    y2.push_back(j+1);
                }
                else{
                    if(i==h-1) continue;
                    a[i+1][j]++;
                    x1.push_back(i);
                    y1.push_back(j);
                    x2.push_back(i+1);
                    y2.push_back(j);
                }
            }
        }
        else{
            for(int j=w-1;j>=0;j--){
                if(a[i][j]%2==0) continue;
                if(j!=0){
                    a[i][j-1]++;
                    x1.push_back(i);
                    y1.push_back(j);
                    x2.push_back(i);
                    y2.push_back(j-1);
                }
                else{
                    if(i==h-1) continue;
                    a[i+1][j]++;
                    x1.push_back(i);
                    y1.push_back(j);
                    x2.push_back(i+1);
                    y2.push_back(j);
                }
            }
        }
    }

    cout<<x1.size()<<endl;
    rep(i,x1.size()){
        cout<<x1[i]+1<<" "<<y1[i]+1<<" "<<x2[i]+1<<" "<<y2[i]+1<<endl;
    }

}


