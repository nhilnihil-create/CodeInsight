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
    int s;
    cin>>s;
    int cnt=1;
    set<int> x;
    x.insert(s);
    while(true){
        if(s%2==0)  s/=2;
        else        s = 3*s+1;
        cnt++;
        if(x.count(s)){
            cout<<cnt<<endl;
            break;
        }
        else{
            x.insert(s);
        }
    }
    return 0;
}

