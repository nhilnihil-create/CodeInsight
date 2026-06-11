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
    string s,t;
    cin>>s;
    cin>>t;
    s += s;

    if (s.find(t) != string::npos)
        cout << "Yes\n";
    else
        cout<<"No\n";

    return 0;
}

