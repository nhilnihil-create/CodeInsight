#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) x.begin(), x.end()

int main() {
    int n,l;
    cin>>n;
    l=n/2;
    vector<int>e(l),o(l);
    rep(i,l)cin>>e[i]>>o[i];
    sort(all(e));
    sort(all(o));
    int cnte=1,cnto=1,emax,omax;
    vector<int>eren(1),oren(1);
    rep(i,l-1){
    	if(e[i]==e[i+1])cnte++;
    	else{
    		eren.push_back(cnte);
    		cnte=1;
    	}
    	if(o[i]==o[i+1])cnto++;
    	else{
    		oren.push_back(cnto);
    		cnto=1;
    	}
    }
    eren.push_back(cnte);
    oren.push_back(cnto);
    sort(all(eren),greater<int>());
    sort(all(oren),greater<int>());
    //cout<<eren[0]<<oren[0];
    cnte=1;cnto=1;
    rep(i,l-1){
    	if(e[i]==e[i+1])cnte++;
    	else{
    		if(cnte==eren[0])emax=e[i];
    		cnte=1;
    	}
    	if(o[i]==o[i+1])cnto++;
    	else{
    		if(cnto==oren[0])omax=o[i];
    		cnto=1;
    	}
    }
    //cout<<emax<<omax;
    if(cnte==eren[0])emax=e[l-1];
    if(cnto==oren[0])omax=o[l-1];
    //cout<<emax<<omax;
    if(emax!=omax)cout<<n-eren[0]-oren[0];
    else cout<<n-max(eren[0]+oren[1],eren[1]+oren[0]);
    return 0;
}