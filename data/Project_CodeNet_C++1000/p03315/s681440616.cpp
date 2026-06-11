#include<bits/stdc++.h>
using namespace std;

int main(){

        char s[100];
        scanf("%s",s);
        int n=0;
        for(int i=0;i<strlen(s);++i){
                if(s[i]=='+'){
                        n++;
                }else{
                        n--;
                }
        }printf("%d\n" ,n);
        return 0;
}

