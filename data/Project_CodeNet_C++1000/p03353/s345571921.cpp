#include<iostream>
#include<set>
using namespace std;
int main() {
    string s;
    int k;
    cin >> s >> k;
    set <string> a;
    for( int i = 1 ; i <= k ; i++ ) {
        for( int j = 0 ; j < s.length() ; j++ ) {
            if( j + i <= s.length() ) a.insert( s.substr( j , i ) );
        }
    }
    auto j = a.begin();
	for ( int i = 0 ; i < k - 1 ; i++ ){ 
      j++;
    }
	  cout << *j << endl;
}