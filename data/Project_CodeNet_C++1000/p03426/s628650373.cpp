#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int h,w,d;
    cin >> h >> w >> d;
    
    vector<P> a(h*w);

    rep(i,h){
        rep(j,w){
            int x;
            cin >> x;
            P p(i,j);
            x--;
            a[x] = p;
        }
    }

    
/*
    for(int i=0;i<h*w; ++i){
        cout << i << ":  "<< a[i].first << ":" << a[i].second << endl;
    }
*/
    

   int vec_num = (h*w)/d+2;
   vector<vector<int>> cum_sum(d,vector<int>(vec_num));
   rep(i,d){
       cum_sum[i][0]=0;
   }

   rep(i,d){
       int temp = i;
       int j = 0;
       while(temp+d<(h*w)){
           cum_sum[i][j+1]=cum_sum[i][j]+ abs(a[temp+d].first-a[temp].first)+abs(a[temp+d].second-a[temp].second);
            temp+=d;
            j++;
       }
   }

/*
   rep(i,d){
       for(auto c:cum_sum[i]) cout << c << " ";
       cout << endl;
   }
   */


    
    int query;
    cin >> query;
    vector<int> res;


    rep(i,query){
        int l,r;
        cin >> l >> r;
        l--; r--;

        int ind = 0;
        ind = l%d;
        l = l/d; r = r/d;
        res.push_back(cum_sum[ind][r]-cum_sum[ind][l]);
        
    }
    

    for(auto r:res) cout << r << endl;

}