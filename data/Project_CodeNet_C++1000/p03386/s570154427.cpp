#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull; 
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define SQ(a) (a)*(a)

template <class T, class U> ostream& operator<< (ostream &out, pair<T,U> c) { out << "(" << c.first << " "; out << c.second << ")"; return out; }
template <class T> ostream& operator<< (ostream &out, vector<T> c) { for (auto it = c.begin(); it != c.end(); ++it) { if (it != c.begin()) out << " "; out << *it; } return out; }
template <class T> ostream& operator<< (ostream &out, set<T> c) { for (auto it = c.begin(); it != c.end(); ++it) { if (it != c.begin()) out << " "; out << *it; } return out; }
const double PI  = 3.141592653589793238463;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, k;
    cin >> a >> b >> k;
    if(b-a+1 <= 2*k){
        FOR(i,a,b+1){
            cout << i << endl;
        }
    }
    else{
        FOR(i,a,a+k){
            cout << i << endl;
        }
        FOR(i,b-k+1, b+1){
            cout << i << endl;
        }
    }
}   