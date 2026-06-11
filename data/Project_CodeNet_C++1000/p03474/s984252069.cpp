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
    int a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    if(s[a]!='-'){
        cout<<"No\n";
        return 0;
    }
    for(int i=0;i<a;i++){
        if(s[i]>=48 && s[i]<=57)    continue;
        else{
            cout<<"No\n";
            return 0;
        }
    }
    for(int i=a+1;i<a+b+1;i++){
        if(s[i]>=48 && s[i]<=57)    continue;
        else{
            cout<<"No\n";
            return 0;
        }
    }

    cout<<"Yes\n";
    return 0;
}

