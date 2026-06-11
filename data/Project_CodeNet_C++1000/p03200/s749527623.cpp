#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin >> str;
    long long n;
    n = str.size();
    long long cnt=0;
    long long bcnt=0;
    for(long long i=0; i<n; i++){
        if(str[i]=='W'){
            cnt = cnt + bcnt;
        }else{
            bcnt++;
        }
    }
    cout << cnt << endl;
}

