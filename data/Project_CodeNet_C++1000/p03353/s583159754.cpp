#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>
#include <iomanip>

using namespace std;
typedef long long ll;
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define all(x) x.begin(),x.end()


int main(){
	string s;cin>>s;
	int k;cin>>k;
	set<string> st;
	for(int l=1; l<=k; ++l){
	    for(int i=0; i+l<=s.size(); ++i){
	        st.insert(s.substr(i,l));
	    }
	}
    auto it=st.begin();
    while(--k)++it;
    cout<<*it<<endl;
}