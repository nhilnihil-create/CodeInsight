#include <bits/stdc++.h>
using namespace std;

int main(){
    string S; cin >> S;
    list<char> Slist, Slist_rev;
    for( int i = 0; i < S.size(); i++ ){
        Slist.emplace_front(S[i]);
        Slist_rev.emplace_back(S[i]);
    }
    auto itr = Slist.begin();
    auto itr_r = Slist_rev.begin();
    int ans = 0;
    while( itr != Slist.end() || itr_r != Slist_rev.end() ){
        if( *itr == *itr_r ){
            itr++;
            itr_r++;
        } else if ( *itr == 'x' ){
            Slist_rev.insert(itr_r,'x');
            itr_r--;
            ans++;
        } else if ( *itr_r == 'x' ){
            Slist.insert(itr,'x');
            itr--;
            ans++;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans/2 << endl;
}