#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    int N;
    int A,B;
    
    cin >> N;
    cin >> A >> B;
    
    int P;
    int a = 0;
    int b = 0;
    int c = 0;
    for(int i = 0; i < N ; i++){
        cin >> P;
        if(P<=A)a++;
        else if(A+1 <= P && P <= B)b++;
        else c++;
    }
    
    cout << min(a,min(b,c))<<endl;
    
    
    
}
    
    

