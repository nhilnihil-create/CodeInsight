#include<iostream>

int main(void){
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;
    k--;
    if(s[k] == 'A') s[k] = 'a';
    else if(s[k] == 'B') s[k] = 'b';
    else s[k] = 'c';
    std::cout << s << std::endl;
    return 0;
}