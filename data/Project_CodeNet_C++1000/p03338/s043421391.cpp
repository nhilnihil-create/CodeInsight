#include<iostream>
#include<string>
#include<algorithm>
#define NO  std::string::npos
int main(){
    std::string S,buf;
    int N;
    std::cin >> N >> S; buf =S;
    std::sort(buf.begin(),buf.end());
    buf.erase(std::unique(buf.begin(), buf.end()), buf.end());
    int m = 0;
    for(int i=0; i < N-1; i++) {
        std::string a = S.substr(0,i+1);
        std::string b = S.substr(i+1);
        int count=0;
        for(auto c:buf)
            if(a.find(c) != NO && b.find(c) != NO) count++;
        if(count > m)  m=count;
    }
    std::cout << m << "\n";

}