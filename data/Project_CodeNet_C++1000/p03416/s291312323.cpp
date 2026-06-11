
#include<iostream> 
using namespace std; 
  
// A function to check if n is palindrome 
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
void countPal(int min, int max) 
{ int count=0;
    for (int i = min; i <= max; i++) 
        if (isPalindrome(i)) 
          count++; 
          cout<<count;
} 
  
// Driver program to test above function 
int main() 
{ int a,b;
cin>>a>>b;
    countPal(a, b); 
    return 0; 
} 