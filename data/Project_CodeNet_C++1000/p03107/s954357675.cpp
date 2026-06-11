/*
ID: learnin7
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
        
    ios_base::sync_with_stdio(0);
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    //fin >> a >> b;
    //fout << a+b << endl;
    string s;
    cin>>s;
    int cnt1=0, cnt0=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0')   cnt0++;
        else            cnt1++;
    }
    cout<<2*min(cnt0,cnt1)<<endl;
    return 0;
}

