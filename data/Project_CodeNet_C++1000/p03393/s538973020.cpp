#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

int main(){
    string s;
    vector<bool> flag(26,false);
    cin >> s;
    string al = "abcdefghijklmnopqrstuvwxyz";
    int len = s.length();
    if(len < 26){
        rep(i,len){
            flag[(int)s[i]-'a']=true;
        }
        cout << s;
        rep(i,26){
            if(!flag[i]){
                cout << al[i] << endl;
                return 0;
            }
        }
    }else{

        if (s == "zyxwvutsrqponmlkjihgfedcba") {
			cout << -1 << endl;
			return 0;
		}
        
		map<char, int> mp;
		for (int i = 25; i > 0; i--) {
			mp[s[i]] = 1;
			s.pop_back();
			for (auto x: mp) {
				if (x.first > s[i - 1]) {
					s[i - 1] = x.first;
					cout << s << endl;
					return 0;
				}
			}
		}
    }

    return 0;
}
