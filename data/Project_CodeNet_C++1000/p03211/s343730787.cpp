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
    int min_diff = INT_MAX;;
    string s;
    cin>>s;
    int n=s.length();
    for(int i=0;i<n-2;i++){
        //string res = "";
        string res =  s.substr(i,3);
        //cout<<res<<endl;
        int x = stoi(res);
        min_diff = min(min_diff,abs(753-x));
    }
    cout<<min_diff<<endl;
    return 0;
}

