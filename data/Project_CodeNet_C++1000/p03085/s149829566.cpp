#include<bits/stdc++.h>
using namespace std;

int main(){
    int T,i,j;
    char ch;
    scanf("%c",&ch);

    map<char,char> mp;

    mp['A']='T';
    mp['T']='A';
    mp['G']='C';
    mp['C']='G';

    printf("%c\n",mp[ch]);

return 0;
}
