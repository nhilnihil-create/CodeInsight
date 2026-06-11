#include <bits/stdc++.h>
using namespace std;


int main(){


    string a, b, c;

    int n, i;

    int k = 0;

    set<char> s;

 
    cin >> n >> a >> b >> c;


    for( i = 0 ; i < n ; i = i + 1 ){

         s.insert( a.at(i) );

         s.insert( b.at(i) );

         s.insert( c.at(i) );

         k += s.size() - 1;

         s.clear();

         }


    cout << k << endl;


    return 0;


    }