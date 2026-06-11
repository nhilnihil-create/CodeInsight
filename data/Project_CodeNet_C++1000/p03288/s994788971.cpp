/*
      author : nishi5451
      created: 11.08.2020 20:48:00
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int R;
    cin >> R;
    if(R<1200) printf("%s\n","ABC");
    else if(R<2800) printf("%s\n","ARC");
    else printf("%s\n","AGC");
    return 0;
}