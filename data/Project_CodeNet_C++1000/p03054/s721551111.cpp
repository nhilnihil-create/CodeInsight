typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll h,w,n;
    std::cin >> h>>w>>n;
    ll sr,sc;
    std::cin >> sr >> sc;
    sr--;
    sc--;
    string s,t;
    std::cin >> s;
    std::cin >> t;
    
    ll l,r;
    l = 0;
    r = w-1;
    for (int i = n-1; i >=0; i--) {
        if(t[i]=='R'){
            l--;
            l = max((ll)0,l);
        }else if(t[i]=='L'){
            r++;
            r = min(w-1,r);
        }
        
        if(s[i]=='R'){
            r--;
        }else if(s[i]=='L'){
            l++;
        }

        if(r<l){
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    if(sc<l || r<sc){
        std::cout << "NO" << std::endl;
        return 0;
    }
    
    l = 0;
    r = h-1;
    for (int i = n-1; i >=0; i--) {
        if(t[i]=='D'){
            l--;
            l = max((ll)0,l);
        }else if(t[i]=='U'){
            r++;
            r = min(h-1,r);
        }
        
        if(s[i]=='D'){
            r--;
        }else if(s[ i]=='U'){
            l++;
        }
        
        if(r<l){
            std::cout << "NO" << std::endl;
            return 0;
        }
    }                                                                                                                                           
    if(sr<l || r<sr){
        std::cout << "NO" << std::endl;
        return 0;
    }
    
    std::cout << "YES" << std::endl;
}
