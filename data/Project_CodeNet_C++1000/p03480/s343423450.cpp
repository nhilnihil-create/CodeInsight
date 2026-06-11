/// I won't go back on my word, that's my ninja way!
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5 ;
string str ;
int solve(char ch){
    int ret = str.size() ;
    for(int i=0;i<str.size();++i)if(str[i]==ch){
        int j = i ;
        while(j<str.size() && str[j]==ch)++j;
        --j ;


        int a = j + 1 ;
        int b = str.size() - i ;

        int a0 = a - (j-i+1) ;
        int b0 = b ;
        int ans0 = min(a,max(a0,b0));


        int a1 = a ;
        int b1 = b - (j-i+1) ;
        int ans1 = min(b,max(a1,b1));

        ret = min(ret ,max(ans0,ans1));

        i = j ;
    }
    return ret ;
}
int main(){
    cin >> str ;
    cout << max(solve('0') ,solve('1')) ;
    return 0 ;
}
