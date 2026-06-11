#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main(){
    int N,x;
    cin>>N>>x;
    vector<int> a(N+1);
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    a[N] = 1000000000;
    sort(a.begin(),a.end());
    int sum = 0;
    int i = 0;
    while(true){
        if(sum+a[i]>x){
            if(i==N)i--;
            break;
        }else if (sum+a[i]==x){
            i++;
            break;
        }else{
            sum += a[i];  
            i++;
        }
    }
    cout<<i<<endl;
}