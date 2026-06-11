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
    int n;
    cin>>n;
    set<string> s;
    string prev = "";
    //bool flag = true;
    vector<string> a;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        string x = a[i];
        
        if(i==0){
            s.insert(x);
            prev = x;
        }
        else{
            if(s.count(x)){
                cout<<"No\n";
                return 0;
            }
            int pl = prev.length();
            if(prev[pl-1]!=x[0]){
                cout<<"No\n";
                return 0;
            }
            prev = x;
            s.insert(x);
        }
    }
    cout<<"Yes\n";
    return 0;
}

