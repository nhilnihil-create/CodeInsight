#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string N;
    cin>>N;
    int A= N.at(0)-'0';
    int B= N.at(1)-'0';
    int C= N.at(2)-'0';
    int D= N.at(3)-'0';
    if(A+B+C+D==7){
        cout<<A <<'+'<< B <<'+'<< C<< '+'<< D <<'='<< 7<<endl;
    }
   else if(A+B+C-D==7){
        cout<<A<< '+'<< B<< '+'<< C <<'-' <<D<< '='<< 7<<endl;
    }
    else if(A+B-C+D==7){
        cout<<A<< '+'<< B <<'-'<< C <<'+'<< D <<'=' <<7<<endl;
    }
 else if(A+B-C-D==7){
        cout<<A <<'+'<< B<< '-'<< C <<'-'<< D<< '='<< 7<<endl;
    }
     else if(A-B+C+D==7){
        cout<<A <<'-'<< B <<'+' <<C <<'+'<< D <<'='<< 7<<endl;
    }
   else  if(A-B+C-D==7){
        cout<<A <<'-'<< B <<'+'<< C <<'-' <<D<< '=' <<7<<endl;
    }
    else if(A-B-C-D==7){
        cout<<A <<'-' <<B <<'-'<< C <<'-' <<D<<'='<< 7<<endl;
    }
    else if(A-B-C+D==7){
        cout<<A <<'-'<< B <<'-'<< C <<'+' <<D <<'=' <<7<<endl;
    }

}