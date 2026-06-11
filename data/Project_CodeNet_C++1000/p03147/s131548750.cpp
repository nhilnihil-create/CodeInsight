#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
using ll = long long;
using P= pair<int,int>;

int main() {
    int N;
    int check=1;
    ll count=0;
    cin>>N;
    vector<int> h(N);
    rep(i,N){cin>>h[i];}
    while(1){
      bool s_flg=false;
      bool all_end_flg=true;
      rep(i,N){
        if(!s_flg){
        	if(h[i]>=check){
              s_flg=true;
              all_end_flg=false;
            }
        }else{
            if(h[i]<check){
              s_flg=false;
              count++;
            }
        }
      }
      if(s_flg)count++;//
      if(all_end_flg)break;
      else{
        check++;
        s_flg=false;
      }
    }//while
    cout<<count<<endl;
    return 0;
}