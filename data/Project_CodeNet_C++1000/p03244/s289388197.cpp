#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int v[n];
    for(int i=0;i<n;i++)cin >> v[i];
    map<int,int>odd;
    map<int,int>even;

    for(int i=0;i<n;i++){
        if(i%2==0)even[v[i]]++;
        else odd[v[i]]++;
    }
    int oddMax = 0;
    int evenMax = 0;
    int oddSub = 0;
    int evenSub = 0;
    
    for(int i=1;i<=100000;i++){
        if(odd[i] >= odd[oddMax]){
            oddSub = oddMax;
            oddMax = i;
        }else if(odd[i] > odd[oddSub]){
            oddSub = i;
        }

        if(even[i] >= even[evenMax]){
            evenSub = evenMax;
            evenMax = i;
        }else if(even[i] > even[evenSub]){
            evenSub = i;
        }
    }
    if(evenMax == oddMax){
        if(odd[oddMax] - odd[oddSub] >= even[evenMax] - even[evenSub])evenMax = evenSub;
        else oddMax = oddSub;
    }
    cout << n-odd[oddMax]-even[evenMax]<<endl;


}