typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    std::cin >> n;
    vector<bool> seats(20);

    string first;
    string last;
    
    ll l,r;
    l = 0;
    r = n-1;
    
    std::cout << 0 << std::endl;
    std::cin >> first;
    if(first == "Vacant")return 0;
    std::cout << n-1 << std::endl;
    std::cin >> last;
    if(last == "Vacant")return 0;
    ll rem =18;
    while(rem>0){
        ll pos = (l+r)/2;
        string tmp;
        std::cout << pos << std::endl;
        std::cin >> tmp;
        
        if(tmp == "Vacant")return 0;
        
        if( (tmp == last) ^ ((r-pos)%2==0)){
            l = pos;
            first = tmp;
        }else{
            r = pos;
            last = tmp;
        }
        
        
        rem--;
    }
}
