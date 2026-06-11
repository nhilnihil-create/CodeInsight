using namespace std;
#include <bits/stdc++.h>

int main(){
    string s;cin>>s;
    sort(s.begin(),s.end());
    if(s=="abc"){
        std::cout << "Yes" << std::endl;
    }
    else{
        std::cout << "No" << std::endl;
    }
    return 0;
}