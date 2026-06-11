#include<bits/stdc++.h>
using namespace std;

int isPalindrome(int n) 
{ 
    // Find reverse of n 
    int rev = 0; 
    for (int i = n; i > 0; i /= 10) 
        rev = rev*10 + i%10; 
  
    // If n and rev are same, then n is palindrome 
    return (n==rev); 
} 
  
// prints palindrome between min and max 
int countPal(int min, int max) 
{ 
    int c=0;
    for (int i = min; i <= max; i++) 
        if (isPalindrome(i)) 
          c++;
  
    return c;
} 

int main()
{
  int l,r;
  cin>>l>>r;
  cout<<countPal(l,r);
  return 0;
}