#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    tuple<string,int,int> r[n];
    int i=0;
    for(i=0;i<n;i++){
        cin >> get<0>(r[i]) >> get<1>(r[i]);
        get<2>(r[i]) = i+1;
    }

    sort(r,r+n);
    int j;
    for(j=0;j<n;j++){
        for(i=0;i<n-1;i++){
            if(get<0>(r[i])==get<0>(r[i+1])){
                if(get<1>(r[i])<get<1>(r[i+1]))
                    swap(r[i],r[i+1]);
            }
        }
    }

    for(i=0;i<n;i++)
        cout << get<2>(r[i]) << endl;
}