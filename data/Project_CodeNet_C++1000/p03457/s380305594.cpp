#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    int n;
    cin >> n;
    int now = 0;
    int now_x = 0;
    int now_y = 0;
    int out = 0;
    rep(i,0,n){
        int t,x,y;
        cin >> t>>x>>y;
        int time = t-now;
        int distance = abs(now_x-x)+abs(now_y-y);
        if(time>=distance&&time%2==distance%2){
            now = t;
            now_x = x;
            now_y = y;
            continue;
        }else{
            out = 1;
            break;
        }
        now = t;
        now_x = x;
        now_y = y;


    }
    if(out==1){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
  return 0;
}