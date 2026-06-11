#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x,y;
    int amax=-100;
    int bmin=100;
    cin >> n >> m >> x >> y;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++){
        cin >> a.at(i);
        if(amax<a.at(i))amax=a.at(i);
        }
    for(int i=0;i<m;i++){
        cin >> b.at(i);
        if(bmin>b.at(i))bmin=b.at(i);
        }
    if((x>=y)||(amax>=bmin)){
        cout << "War" << endl;
        return 0;
    }
    if(max(x,amax)>=min(y,bmin)){
        cout << "War" << endl;
        return 0;
    }
    cout << "No War" << endl;

    return 0;
}