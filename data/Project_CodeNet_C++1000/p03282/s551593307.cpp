#include<iostream>
#include<string>
#include <cmath>
#include <typeinfo>
#define FOR(i,a,b) for(int i = a;i<=b; i++)
#define days 5*1e15
using namespace std;

string convertString(string a){
    string ans;
    long long b = stoi(a);
    double sum = (pow(10,b) - 1)/9;
    b *= sum;
    ans = to_string(b);
    return ans;
}

int main() {
//    long double sum;
//    for(int i = 0; i<str.length();i++){
//        long long b = str[i] - '0';
//        sum = (pow(10,(long long)pow(2,days)) - 1)/9;
//        b *= sum;
//        ans += to_string(b);
//    }
    string str;
    long long count = 0, i = 0, ans;
    long long k;
    getline(cin, str);
    cin >> k;
    if((str[0]-'0') != 1) cout << str[0];
    else{
        while((str[i]-'0') == 1){
        count++;
        i++;
    }
    if(count >= k) cout << 1;
    else {
        ans = str[count]-'0';
        cout << ans;
        }
    }

}





