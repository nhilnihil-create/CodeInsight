//(・ω・)
#include <stdio.h>
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, atoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <iomanip> //setprecision
#include <limits>
#include <sstream> //istringstream
#include <stdlib.h>
#include <list>
#include <iterator>//std::advance()
using namespace std;

int main(){
    string s1,t;
    long long sum=0;
    vector<string> ans;
    cin >> s1 >> t;
    for(int i=0; i<s1.size(); i++){
        if(s1[i]==t[0] || s1[i]=='?'){
            bool same=1;
            for(int j=0; j<t.size(); j++){
                if(s1[i+j]!=t[j] && s1[i+j]!='?'){
                    same=0;
                    break;
                }
            }
            if(same){
                sum++;
                string s=s1;
                for(int j=0; j<s1.size(); j++){
                    if(j>=i && j<=i+t.size()-1)  s[j]=t[j-i];
                    else if(s[j]=='?') s[j]='a';
                }
                ans.push_back(s);
            }
        }
    }
    if(sum==0) cout << "UNRESTORABLE" << endl;
    else{
        sort(ans.begin(),ans.end());
        cout << ans[0] << endl;
    }
}
