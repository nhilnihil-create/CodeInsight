#include <iostream>
#include <cstdio>
#include <map>
using namespace std;



int length = 0;





int main(){
    int n; 
    string s;
    cin >> n;
    cin >> s;

    map<char, long long> T;
    long long mod = 1000000007;
                    

    

    for(int i = 0; i < s.size(); i++){
        if(T.find(s[i]) == T.end()){
            T[s[i]]= 1;
        }
        else{
            T[s[i]]++;
        }
       
    }

    long long sum = 1;

    map<char, long long>::iterator it;

    for(it = T.begin(); it != T.end(); it++){
        sum = sum*(it->second+1);
        sum = sum%mod;
    }
    

    printf("%lld\n", sum-1);

    return 0;

}