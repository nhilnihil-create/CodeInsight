    #include <bits/stdc++.h>
    #define rep(i,n) for (int i = 0; i < (n); ++i)
    #define P pair<int,int>
    using ll=int64_t;
    using namespace std;
    #define ketasuu(n) fixed<<setprecision(n)
    #define btoe(p) p.begin(),p.end()
    #define etob(p) p.rbegin(),p.rend()




    int main(){
        int h,w; cin>>h>>w;
        vector<vector<int>> p(h,vector<int>(w));
        rep(i,h) rep(j,w) cin>>p[i][j];
        vector<tuple<int,int,int,int>> ans;
        rep(i,h){
            rep(j,w-1){
                if(p[i][j]%2==1){
                    ans.emplace_back(i,j,i,j+1);
                    p[i][j+1]++;
                }
            }
        }
        rep(i,h-1){
            if(p[i][w-1]%2==1){
                ans.emplace_back(i,w-1,i+1,w-1);
                p[i+1][w-1]++;
            }
        }
        int n=ans.size();
        cout<<n<<endl;
        for(auto& v: ans){
            cout<<get<0>(v)+1<<" "<<get<1>(v)+1<<" "<<get<2>(v)+1<<" "<<get<3>(v)+1<<endl;
        }
        return 0;
    }