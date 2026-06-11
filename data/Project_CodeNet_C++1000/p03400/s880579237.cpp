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
    int n,d,x;
    cin>>n;
    cin>>d>>x;
    int a[n];
    for(int i=0;i<n;i++)    cin>>a[i];
    int tot=0;
    for(int i=0;i<n;i++){
        int cnt=0,j=0;
        while(1 + j*a[i] <= d){
            cnt++;
            j++;
        }
        tot += cnt;
    }
    cout<<tot+x<<endl;
    return 0;
}

