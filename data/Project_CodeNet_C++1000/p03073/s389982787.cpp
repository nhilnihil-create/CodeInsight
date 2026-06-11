#include <bits/stdc++.h>
//#define DEBUG
#define REP( i , nn ) for(int i = 0 ; i < (int) nn; i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
template <class T>
void print_vect(std::vector<T> v){
    for(int i = 0 ; i < v .size(); i++) cout << v[i] << " ";
    cout << endl;
}

void solve(){
    string S;
    cin >> S;
    int ans1 = 0;
    char next_color = '0';
    REP(i, S.size()){
        if( S[i] != next_color){
            ans1++;
        }
        next_color = '0' + 1 - (next_color - '0');
    }
    next_color = '1';
    int ans2 = 0;
    REP(i, S.size()){
        if( S[i] != next_color){
            ans2++;
        }
        next_color = '0' + 1 - (next_color - '0');
    }
    cout << min(ans1, ans2) << "\n";
} 

int main()
{
    //making data IO Fast
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /****************************/

    #ifdef DEBUG
    int TEST_CASES = 2;
    while(TEST_CASES--){
    #endif // DEBBUG

    solve();

    #ifdef DEBUG
    }
    #endif // DEBUG
    
    return 0;
}

//Thanks to CSES problemset
// I am trained with this kind of problem