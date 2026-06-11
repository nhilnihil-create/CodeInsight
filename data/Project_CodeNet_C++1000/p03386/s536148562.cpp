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
    int a,b,k;
    cin>>a>>b>>k;
    set<int> x;
    
    k = min(k,(b-a+1));
    for(int i=a;i<=a+k-1;i++){
        x.insert(i);
    }
    for(int i=b-k+1;i<=b;i++){
        x.insert(i);
    }
    for(auto i:x){
        cout<<i<<endl;
    }
    return 0;
}

