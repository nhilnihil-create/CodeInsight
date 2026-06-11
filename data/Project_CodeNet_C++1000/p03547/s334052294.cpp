# include <bits/stdc++.h>

int main(void){
    char a,b;
    std::cin>>a>>b;    
    if(a<b)
        putchar('<');
    else if(a==b)
        putchar('=');
    else
        putchar('>');
    puts("");
    return 0;
}