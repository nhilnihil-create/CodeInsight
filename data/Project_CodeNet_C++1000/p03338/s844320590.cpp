#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int check[26]={0};
    int count=0;
    int max=0;
    int i,j,k;

    for(i=0; i<N-1; i++){
        count=0;
        for(j=0; j<i+1; j++){
            for(k=0; k<26; k++){
                if(S[j]=='a'+k) check[k]=1;
            }
        }
        for(j=i+1; j<N; j++){
            for(k=0; k<26; k++){
                if(S[j]=='a'+k){
                    if(check[k]==1) check[k]++;
                }
            }
        }
        for(k=0; k<26; k++){
            if(check[k]==2) count++;
        }
        if(max<count) max=count;
        count=0;
    }

    cout << max << endl;
}