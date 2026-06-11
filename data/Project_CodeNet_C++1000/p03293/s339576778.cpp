#include<iostream>
int main(){std::string S,T;std::cin>>S>>T;puts(~(S+S).find(T)?"Yes":"No");}