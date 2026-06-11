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
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)   cin>>a[i];
    
    sort(a,a+n);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(i==n-1){
            if(a[i]==x) cnt++;
        }
        else{
            if(x-a[i]>=0){
                cnt++;
                x -= a[i];
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}

