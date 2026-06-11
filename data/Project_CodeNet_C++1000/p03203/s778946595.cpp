#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <functional>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstdio>
#define ll long long
#define INF 1e+7
#define MOD 1000000007
using namespace std;



int main(){
    int ans=INF;
    
    int H,W,N;
    cin>>H>>W>>N;
    
    pair<int,int> sgb[N];
    for(int i=0; i<N; i++){
        cin >> sgb[i].first >> sgb[i].second;
        sgb[i].first--;
        sgb[i].second--;
    }
    
  
    map<int, int> sgb_exist[W];
    for(int i=0; i<N; i++){
        sgb_exist[sgb[i].second].insert( make_pair(sgb[i].first,1) );
    }
    
    vector<int> sgb_x[W];
    for(int i=0; i<N; i++){
        sgb_x[sgb[i].second].push_back(sgb[i].first);
    }
    
    for(int i=0; i<W; i++){
        sort(sgb_x[i].begin(), sgb_x[i].end());
    }
    
    
    int x=0;
    int y=0;
    

    for(int i=0; i<W; i++){
        int tmp=INF;
        
        if(sgb_x[i].size()==0){
            ans=min(ans,H);
        }else{
            int bound = lower_bound(sgb_x[i].begin(), sgb_x[i].end(), x) - sgb_x[i].begin();
            if(bound==sgb_x[i].end()-sgb_x[i].begin()){
                tmp=H;
            }else{
                tmp=sgb_x[i][bound];
            }
            
            
            ans=min(tmp,ans);
        }
    //    cout << "y=" << i <<"; tmp=" <<tmp<<endl;
        
        
        int next=1;
        if(i==W-1){
            next=0;
        }else{
            if(x==H-1){
                break;
            }
            
            if(sgb_exist[i].count(x+1)==0){
                x++;
            }else{
                break;
            }
            
            if(sgb_exist[i+1].count(x)==0){
                next=1;
            }else{
                while(sgb_exist[i+1].count(x)>0){
                    if(x==H-1 || sgb_exist[i].count(x)>0){
                        next=0;
                        break;
                    }else{
                        x++;
                    }
                }
                
            }
        }
        
        if(next==0){
            break;
        }
    }
    

    
    
    cout<<ans<<endl;
    return 0;
}
