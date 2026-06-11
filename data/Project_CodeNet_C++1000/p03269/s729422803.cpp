#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define st first
#define nd second	
typedef pair < int , int > pp;

signed main(){
	int L;
    cin >> L;
    int t = 1;
    vector < pair< pp , int > > ans;
    for(int i=19; i>=2; i--){
        ans.pb(mp(mp(i,i+1),0));
        ans.pb(mp(mp(i,i+1),t));
        t = t+t;
    }
    
    t = 0;
    for(int i=0; i<=18; i++){
        if(L & (1 << i)){
	        ans.pb(mp(mp(1,20-i),t));
            t += (1 << i);
        }
    }
    
    if(L & (1 << 19)){
        ans.pb(mp(mp(1,2),t));
        t += (1 << 18);
        ans.pb(mp(mp(1,2),t));
    }
        
    cout << "20 " << ans.size() << endl;
    for(int i=0; i<ans.size(); i++)
        cout << ans[i].st.st << " " << ans[i].st.nd << " " << ans[i].nd << endl;
    
    return 0;
}