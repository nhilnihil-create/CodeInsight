#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int d[n];
    int i;
    for(i=0;i<n;i++)
        cin >> d[i];

    sort(d,d+n);
    int top=d[0],counter=1;
    for(i=1;i<n;i++){
        if(top<d[i]){
            counter++;
            top=d[i];
        }
    }
    cout << counter << endl;
}