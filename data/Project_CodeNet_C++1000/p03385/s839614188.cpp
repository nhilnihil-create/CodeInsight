#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {

    string s ;
    cin >> s  ;

    int ans[3] ;
    ans[0] = ans[2] = ans[1] = 0 ; 
    for (int i = 0; i < 3; i++)
    {
        if(s[i]=='a') ans[0] += 1 ;
        if(s[i]=='b') ans[1] += 1 ;
        if(s[i]=='c') ans[2] += 1 ;
    }
    
    bool Answer = false ;
    if(ans[0]==1 && ans[1]==1 && ans[2]==1) Answer = true ;

    if(Answer)
     cout << "Yes" << endl ;
    else 
     cout << "No" << endl ;     

    return 0;
}
