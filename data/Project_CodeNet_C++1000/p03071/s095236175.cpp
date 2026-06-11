    #include <iostream>
    using namespace std;
    int main()
    {
      int a, b, c, d, e;
      cin>> a>> b;
      c=2*a-1;
      d=2*b-1;
      e=a+b;
      if (c>=d && c>=e){
        cout<<c;
      }else if (d>=c && d>=e){
        cout<<d;
      }else if (e>=d && e>=c){
        cout<<e;
      }
    }