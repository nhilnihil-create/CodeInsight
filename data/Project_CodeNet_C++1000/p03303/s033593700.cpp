#include <bits/stdc++.h>

using namespace std;

int main()
{
   string str ;
   cin>>str;
   int n;
   cin>>n;
    for(int i=0; i<=str.size()-1; ++i){
        if(i%n == 0) cout<<str[i];
    }
    return 0;
}
