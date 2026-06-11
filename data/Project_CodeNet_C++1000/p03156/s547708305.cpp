#include <bits/stdc++.h>
using namespace std;
 


 
int main() {


    int n;
    cin>>n;

    int a,b;
    cin>>a>>b;

    vector<int> p(n);
    for(int i=0;i<n;i++){
        cin>>p.at(i);
    }

    int prob1_cnt=0,prob2_cnt=0,prob3_cnt=0;
    for(int i=0;i<n;i++){
        if(p.at(i)<=a)
            prob1_cnt++;
        else if(p.at(i)>a && p.at(i)<=b)
            prob2_cnt++;
        else
            prob3_cnt++;
    }

    cout<<min(min(prob1_cnt,prob2_cnt),prob3_cnt)<<endl;

 	return 0;
}
