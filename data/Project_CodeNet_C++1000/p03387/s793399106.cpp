#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main(){
    int a, b, c;
    std::cin >> a >> b >> c;
    // aを最大にする
    if(a < std::max(b, c)){
        if(b <= c){
            std::swap(a, c);
        }else{
            std::swap(a, b);
        }
    }

    int offset = 0;
    if(a % 2 == b % 2 && a % 2 != c % 2){
        a += 1;
        b += 1;
        offset++;
    }else if(a % 2 != b % 2 && a % 2 == c % 2){
        a += 1;
        b += 1;
        offset++;
    }

    int cost = a - std::max(b, c);
    b += cost;
    c += cost;
    if(a != b){
        cost += (a - b) / 2;
    }else if(a != c){
        cost += (a - c) / 2;
    }
    std::cout << cost + offset << std::endl;
    return 0;
}
