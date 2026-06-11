#include<bits/stdc++.h>

int main()
{
    int n;
    std::string s;
    std::cin >> n >> s;
    s += '#';
    int w = 0;
    for(int i = 0; i <= n; i++){
        if(s[i] == '.')w++;
    }
    
    int rw = w, lb = 0, min = INT_MAX;

    for(int i = 0; i <= n; i++){
        min = std::min(min,rw + lb);
            if(s[i] == '#')lb++;
            else rw--;
    }
    std::cout << min << std::endl;
}