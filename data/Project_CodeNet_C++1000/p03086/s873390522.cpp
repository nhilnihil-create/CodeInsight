#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    string s;
    cin >> s;
    int c = 0, m = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A' || s[i] == 'T' || s[i] =='G' || s[i] == 'C'){
            c++;
        }
        else{
            c = 0;
        }
        m = max(c, m);
    }
    cout << m;



}





///promy_pompom
//hello world
