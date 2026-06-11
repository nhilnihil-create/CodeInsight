#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin >> s;
    int count=0;
    int maxx=0;

    for(int i=0;i<s.size();i++){
        if(s.at(i)=='A'||s.at(i)=='C'||s.at(i)=='G'||s.at(i)=='T'){
            count++;
        }
        else{
            count = 0;
            continue;
        }
        maxx=max(count,maxx);
        
    }
    cout << maxx <<endl;
}