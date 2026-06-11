//
//  main.cpp
//  C
//
//  Created by 曾憲揚 on 2020/9/7.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, k; cin>>n>>k;
    
    double ans=0;
    
    for(int i=1; i<=n; i++){
        double sc = 1.0/n;
        int reg=i;
        while(reg<k){
            sc/=2;
            reg*=2;
        }
        ans+=sc;
    }
    
    printf("%.9f\n", ans);
    return 0;
}
