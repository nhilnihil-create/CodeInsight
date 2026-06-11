#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define mem(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, int> pli;

const int mn = 3e5 + 5;
const int maxlog = 19;

const string s[]={"KIHBR","KIHBRA","KIHBAR","KIHBARA","KIHABR","KIHABRA","KIHABAR","KIHABARA",
                  "AKIHBR","AKIHBRA","AKIHBAR","AKIHBARA","AKIHABR","AKIHABRA","AKIHABAR","AKIHABARA"};

int main() {
    //cin.sync_with_stdio(0);
#ifdef trote
    freopen("../1.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    string c;
    cin>>c;
    for(auto &i:s){
        if (c==i) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}