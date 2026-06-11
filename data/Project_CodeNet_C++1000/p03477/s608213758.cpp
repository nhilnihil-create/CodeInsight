        #include <bits/stdc++.h>
            using namespace std;
             
            int main() {
              int x=0,y=0,z=0,w=0;
              cin >>x >>y>>z>>w;
              int l=x+y;
              int r=z+w;
              if (l==r){cout<<"Balanced";} else if (l>r) {cout<<"Left";} else {cout<<"Right";};
              
            }